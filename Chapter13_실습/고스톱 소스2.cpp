#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "cursor.h"
#include <assert.h>
#include <iostream>
using namespace std;

const int MaxCard = 48;
const int CardGap = 4;
const int Speed = 1000;
const int PromptSpeed = 2000;

// 화투 한장을 표현하는 클래스
struct SCard
{
	char Name[4];
	SCard() { Name[0] = 0; }
	SCard(const char* pName) {
		strcpy(Name, pName);
	}
	int GetNumber() const {
		if (isdigit(Name[0])) return Name[0] - '0';
		if (Name[0] == 'J') return 10;
		if (Name[0] == 'D') return 11;
		return 12;
	};
	int GetKind() const {
		if (strcmp(Name + 1, "광") == 0) return 0;
		else if (strcmp(Name + 1, "십") == 0) return 1;
		else if (strcmp(Name + 1, "오") == 0) return 2;
		else if (strcmp(Name + 1, "쌍") == 0) return 3;
		else return 4;
	}
	friend ostream& operator <<(ostream& c, const SCard& C) {
		return c << C.Name;
	}
	bool operator ==(const SCard& Other) const {
		return (strcmp(Name, Other.Name) == 0);
	}
	bool operator <(const SCard& Other) const {
		if (GetNumber() < Other.GetNumber()) return true;
		if (GetNumber() > Other.GetNumber()) return false;
		if (GetKind() < Other.GetKind()) return true;
		return false;
	}
};

// 화투의 초기 카드 목록
SCard HwaToo[MaxCard] = {
	"1광","1오","1피","1피","2십","2오","2피","2피","3광","3오","3피","3피",
	"4십","4오","4피","4피","5십","5오","5피","5피","6십","6오","6피","6피",
	"7십","7오","7피","7피","8광","8십","8피","8피","9십","9오","9피","9피",
	"J십","J오","J피","J피","D광","D쌍","D피","D피","B광","B십","B오","B쌍"
};

// 카드의 집합을 관리하는 클래스
class CCardSet
{
protected:
	SCard Card[MaxCard];
	int Num;
	const int sx, sy;
	CCardSet(int asx, int asy) : sx(asx), sy(asy) { Num = 0; }

public:
	int GetNum() { return Num; }
	SCard GetCard(int idx) { return Card[idx]; }
	void Reset() {
		for (int i = 0; i < MaxCard; i++) Card[i].Name[0] = 0;
		Num = 0;
	}
	void InsertCard(SCard C);
	SCard RemoveCard(int idx);
	int FindSameCard(SCard C, int* pSame);
	int FindFirstCard(const char* pName);
	int GetMaxSeries();
};

void CCardSet::InsertCard(SCard C) {
	int i;

	if (C.Name[0] == 0) return;
	for (i = 0; i < Num; i++) {
		if (C < Card[i]) break;
	}
	memmove(&Card[i + 1], &Card[i], sizeof(SCard) * (Num - i));
	Card[i] = C;
	Num++;
}

SCard CCardSet::RemoveCard(int idx) {
	assert(idx < Num);
	SCard C = Card[idx];
	memmove(&Card[idx], &Card[idx + 1], sizeof(SCard) * (Num - idx - 1));
	Num--;
	return C;
}

int CCardSet::FindSameCard(SCard C, int* pSame) {
	int i, num;
	int* p = pSame;

	for (i = 0, num = 0; i < Num; i++) {
		if (Card[i].GetNumber() == C.GetNumber()) {
			num++;
			*p++ = i;
		}
	}
	*p = -1;
	return num;
}

int CCardSet::FindFirstCard(const char* pName) {
	int i;

	for (i = 0; i < Num; i++) {
		if (strstr(Card[i].Name, pName) != NULL) {
			return i;
		}
	}
	return -1;
}

int CCardSet::GetMaxSeries() {
	int i, n, m, old = -1;

	for (i = 0, n = 1, m = 1; i < Num; i++) {
		if (old == Card[i].GetNumber()) {
			n++;
			m = max(n, m);
		}
		else {
			n = 1;
			old = Card[i].GetNumber();
		}
	}
	return m;
}

// 담요 중앙에 카드를 쌓아 놓는 데크
class CDeck : public CCardSet
{
public:
	CDeck(int asx, int asy) : CCardSet(asx, asy) { ; }
	void Shuffle() {
		int i, n;
		for (i = 0; i < MaxCard; i++) {
			do {
				n = random(MaxCard);
			} while (Card[n].Name[0] != NULL);
			Card[n] = HwaToo[i];
			Num++;
		}
	}
	SCard Pop() { return RemoveCard(Num - 1); }
	bool IsEmpty() { return Num == 0; }
	bool IsNotLast() { return Num > 1; }
	void Draw(bool bFlip) {
		gotoxy(sx, sy);
		cout << "??? " << (bFlip ? Card[Num - 1].Name : "   ");
	}
};

// 게임을 하는 플레이어
class CPlayer : public CCardSet
{
public:
	CPlayer(int asx, int asy) : CCardSet(asx, asy) { ; }
	void Draw(bool MyTurn) {
		int i, x;
		for (i = 0, x = sx; i < Num; i++, x += CardGap) {
			gotoxy(x, sy);
			cout << Card[i];
			if (MyTurn) {
				gotoxy(x, sy + 1);
				cout << '[' << i + 1 << ']';
			}
		}
	}
};

// 게임이 진행되는 담요
class CBlanket : public CPlayer
{
public:
	CBlanket(int asx, int asy) : CPlayer(asx, asy) { ; }
	void Draw() {
		CPlayer::Draw(false);
	}
	void DrawSelNum(int* pSame) {
		int n;
		int* p;
		for (n = 1, p = pSame; *p != -1; p++, n++) {
			gotoxy(sx + *p * CardGap, sy - 1);
			cout << '[' << n << ']';
		}
	}
	void DrawTempCard(int idx, SCard C) {
		gotoxy(sx + idx * CardGap, sy + 1);
		cout << C;
	}
};

// 플레이어가 먹은 카드의 집합
class CPlayerPae : public CCardSet
{
private:
	int nGo;

public:
	int OldScore;
	int bShake;
	CPlayerPae(int asx, int asy) : CCardSet(asx, asy) { OldScore = 6; nGo = 0; bShake = false; }
	void Reset() { CCardSet::Reset(); OldScore = 6; nGo = 0; bShake = false; }
	int GetGo() { return nGo; }
	void IncreaseGo() { nGo++; }
	void Draw();
	int RemovePee(int n, SCard* pCard);
	int CalcScore();
};

void CPlayerPae::Draw() {
	int i, kind;
	int x[4] = { sx,sx,sx,sx }, py = sy + 3;

	for (i = 0; i < Num; i++) {
		kind = Card[i].GetKind();
		if (kind < 3) {
			gotoxy(x[kind], sy + kind);
			x[kind] += CardGap;
		}
		else {
			gotoxy(x[3], py);
			x[3] += CardGap;
			if (x[3] > 75) {
				x[3] = sx;
				py++;
			}
		}
		cout << Card[i];
	}
	gotoxy(sx + 20, sy);
	cout << "점수:" << CalcScore() << "점, " << nGo << "고 "
		<< (bShake ? "흔듬" : "");
}

int CPlayerPae::RemovePee(int n, SCard* pCard) {
	int ns = 0, np = 0, tp;
	int i, idx, num = 0;
	SCard* p = pCard;

	for (i = 0; i < Num; i++) {
		if (Card[i].GetKind() == 3) ns++;
		if (Card[i].GetKind() == 4) np++;
	}
	tp = ns + np;
	if (tp == 0) return 0;

	switch (n) {
	case 1:
		if (np != 0) {
			*p++ = RemoveCard(FindFirstCard("피"));
			return 1;
		}
		else {
			*p++ = RemoveCard(FindFirstCard("쌍"));
			return 1;
		}
		break;
	case 2:
		if (ns != 0) {
			*p = RemoveCard(FindFirstCard("쌍"));
			return 1;
		}
		else {
			*p++ = RemoveCard(FindFirstCard("피"));
			num = 1;
			if (np >= 2) {
				*p++ = RemoveCard(FindFirstCard("피"));
				num = 2;
			}
			return num;
		}
	case 3:
		i = RemovePee(2, p);
		p += i;
		idx = RemovePee(1, p);
		return i + idx;
	default:
		return 0;
	}
}

int CPlayerPae::CalcScore() {
	int i, kind, n[4] = { 0, };
	int NewScore;
	static int gscore[] = { 0,0,0,3,4,15 };

	for (i = 0; i < Num; i++) {
		kind = Card[i].GetKind();
		if (kind == 3) n[kind]++;
		if (kind >= 3) kind = 3;
		n[kind]++;
	}
	NewScore = gscore[n[0]];
	if (n[0] == 3 && FindFirstCard("B광") != -1) NewScore--;
	if (n[1] >= 5) NewScore += (n[1] - 4);
	if (n[2] >= 5) NewScore += (n[2] - 4);
	if (n[3] >= 10) NewScore += (n[3] - 9);
	if (FindFirstCard("8십") != -1 && FindFirstCard("5십") != -1 && FindFirstCard("2십") != -1) NewScore += 5;
	if (FindFirstCard("1오") != -1 && FindFirstCard("2오") != -1 && FindFirstCard("3오") != -1) NewScore += 3;
	if (FindFirstCard("4오") != -1 && FindFirstCard("5오") != -1 && FindFirstCard("7오") != -1) NewScore += 3;
	if (FindFirstCard("9오") != -1 && FindFirstCard("J오") != -1 && FindFirstCard("6오") != -1) NewScore += 3;
	return NewScore;
}

// 함수 원형
void Initialize();
void DrawScreen();
void OutPrompt(const char* Mes, int Wait = 0);
int InputInt(const char* Mes, int start, int end);

// 전역 변수
CDeck Deck(18, 9);
CPlayer South(5, 20), North(5, 1);
CBlanket Blanket(5, 12);
CPlayerPae SouthPae(40, 14), NorthPae(40, 4);
bool SouthTurn;

// 프로그램을 총지휘하는 main 함수
void main()
{
	int i, ch;
	int arSame[4], SameNum;
	char Mes[256];
	CPlayer* Turn;
	CPlayerPae* TurnPae, * OtherPae;
	int UserIdx, UserSel, DeckSel;
	SCard UserCard, DeckCard;
	bool UserTriple, DeckTriple;
	int nSnatch;
	int NewScore;
	SCard arPee[3];
	int nPee;
	CPlayer* LastGo = NULL;

	randomize();
	Initialize();
	DrawScreen();
	if (South.GetMaxSeries() == 3) {
		ch = InputInt("같은 카드가 세 장입니다. (1:흔들기, 2:그냥 하기) ", 1, 2);
		if (ch == 1) SouthPae.bShake = true;
	}
	if (North.GetMaxSeries() == 3) {
		ch = InputInt("같은 카드가 세 장입니다. (1:흔들기, 2:그냥 하기) ", 1, 2);
		if (ch == 1) NorthPae.bShake = true;
	}
	for (SouthTurn = true; !Deck.IsEmpty(); SouthTurn = !SouthTurn) {
		DrawScreen();
		if (SouthTurn) {
			Turn = &South;
			TurnPae = &SouthPae;
			OtherPae = &NorthPae;
		}
		else {
			Turn = &North;
			TurnPae = &NorthPae;
			OtherPae = &SouthPae;
		}

		sprintf(Mes, "내고 싶은 화투를 선택하세요(1~%d,0:종료) ", Turn->GetNum());
		ch = InputInt(Mes, 0, Turn->GetNum());
		if (ch == 0) {
			if (InputInt("정말 끝낼겁니까?(0:예,1:아니오)", 0, 1) == 0)
				return;
			else
				continue;
		}

		// 플레이어가 카드를 한장 낸다.
		UserTriple = DeckTriple = false;
		UserIdx = ch - 1;
		UserCard = Turn->GetCard(UserIdx);
		SameNum = Blanket.FindSameCard(UserCard, arSame);
		switch (SameNum) {
		case 0:
			UserSel = -1;
			Blanket.InsertCard(Turn->RemoveCard(UserIdx));
			DrawScreen();
			break;
		case 1:
			UserSel = arSame[0];
			break;
		case 2:
			if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) {
				UserSel = arSame[0];
			}
			else {
				Blanket.DrawSelNum(arSame);
				sprintf(Mes, "어떤 카드를 선택하시겠습니까?(1~%d)", SameNum);
				UserSel = arSame[InputInt(Mes, 1, SameNum) - 1];
			}
			break;
		case 3:
			UserSel = arSame[1];
			UserTriple = true;
			break;
		}
		if (UserSel != -1) {
			Blanket.DrawTempCard(UserSel, UserCard);
		}
		delay(Speed);

		// 데크에서 한장을 뒤집는다.
		Deck.Draw(true);
		delay(Speed);
		DeckCard = Deck.Pop();
		SameNum = Blanket.FindSameCard(DeckCard, arSame);
		switch (SameNum) {
		case 0:
			DeckSel = -1;
			break;
		case 1:
			DeckSel = arSame[0];
			if (DeckSel == UserSel) {
				if (Deck.IsNotLast()) {
					Blanket.InsertCard(DeckCard);
					Blanket.InsertCard(Turn->RemoveCard(UserIdx));
					OutPrompt("설사했습니다.", PromptSpeed);
					continue;
				}
				else {
					DeckSel = -1;
				}
			}
			break;
		case 2:
			if (UserSel == arSame[0]) {
				DeckSel = arSame[1];
			}
			else if (UserSel == arSame[1]) {
				DeckSel = arSame[0];
			}
			else {
				if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) {
					DeckSel = arSame[0];
				}
				else {
					Blanket.DrawSelNum(arSame);
					sprintf(Mes, "어떤 카드를 선택하시겠습니까?(1~%d)", SameNum);
					DeckSel = arSame[InputInt(Mes, 1, SameNum) - 1];
				}
			}
			break;
		case 3:
			DeckSel = arSame[1];
			DeckTriple = true;
			break;
		}
		if (DeckSel != -1) {
			Blanket.DrawTempCard(DeckSel, DeckCard);
		}
		Deck.Draw(false);
		delay(Speed);

		// 일치하는 카드를 거둬 들인다. 세 장을 먹은 경우는 전부 가져 온다.
		if (UserSel != -1) {
			if (UserTriple) {
				for (i = 0; i < 3; i++) {
					TurnPae->InsertCard(Blanket.RemoveCard(UserSel - 1));
				}
			}
			else {
				TurnPae->InsertCard(Blanket.RemoveCard(UserSel));
			}
			TurnPae->InsertCard(Turn->RemoveCard(UserIdx));
			if (DeckSel != -1 && DeckSel > UserSel) {
				DeckSel -= (UserTriple ? 3 : 1);
			}
		}
		if (DeckSel != -1) {
			if (DeckTriple) {
				for (i = 0; i < 3; i++) {
					TurnPae->InsertCard(Blanket.RemoveCard(DeckSel - 1));
				}
			}
			else {
				TurnPae->InsertCard(Blanket.RemoveCard(DeckSel));
			}
			TurnPae->InsertCard(DeckCard);
		}
		else {
			Blanket.InsertCard(DeckCard);
		}

		// 쪽, 따닥, 싹쓸이 조건을 점검하고 상대방의 피를 뺏는다.
		nSnatch = 0;
		if (Deck.IsNotLast()) {
			if (UserSel == -1 && SameNum == 1 && DeckCard.GetNumber() == UserCard.GetNumber()) {
				nSnatch++;
				OutPrompt("쪽입니다.", PromptSpeed);
			}
			if (UserSel != -1 && SameNum == 2 && DeckCard.GetNumber() == UserCard.GetNumber()) {
				nSnatch++;
				OutPrompt("따닥입니다.", PromptSpeed);
			}
			if (Blanket.GetNum() == 0) {
				nSnatch++;
				OutPrompt("싹쓸이입니다.", PromptSpeed);
			}
			if (UserTriple || DeckTriple) {
				OutPrompt("한꺼번에 세 장을 먹었습니다.", PromptSpeed);
				nSnatch += UserTriple + DeckTriple;
			}
		}
		nPee = OtherPae->RemovePee(nSnatch, arPee);
		for (i = 0; i < nPee; i++) {
			TurnPae->InsertCard(arPee[i]);
		}

		// 점수를 계산하고 고, 스톱 여부를 질문한다.
		NewScore = TurnPae->CalcScore();
		if (Deck.IsNotLast() && NewScore > TurnPae->OldScore) {
			DrawScreen();
			if (InputInt("추가 점수를 획득했습니다.(0:스톱, 1:계속)", 0, 1) == 1) {
				TurnPae->OldScore = NewScore;
				TurnPae->IncreaseGo();
				LastGo = Turn;
			}
			else {
				break;
			}
		}
	}
	DrawScreen();

	// 승부와 피박, 광박, 독박 여부를 판정한다.
	bool SouthWin;
	int SouthScore, NorthScore;
	int TurnPee = 0, TurnLight = 0, OtherPee = 0, OtherLight = 0;

	if (Deck.IsEmpty()) {
		if (LastGo != NULL) {
			SouthWin = (LastGo == &North);
		}
		else {
			SouthScore = SouthPae.CalcScore();
			NorthScore = NorthPae.CalcScore();
			if (SouthScore < 7 && NorthScore < 7) {
				OutPrompt("양쪽 모두 기본 점수를 얻지 못해 비겼습니다.");
				return;
			}
			SouthWin = (SouthScore > NorthScore);
		}
	}
	else {
		SouthWin = SouthTurn;
	}
	sprintf(Mes, "%s군이 이겼습니다. ", SouthWin ? "남" : "북");

	if (SouthWin) {
		TurnPae = &SouthPae;
		OtherPae = &NorthPae;
	}
	else {
		TurnPae = &NorthPae;
		OtherPae = &SouthPae;
	}
	for (i = 0; i < TurnPae->GetNum(); i++) {
		if (TurnPae->GetCard(i).GetKind() >= 3) TurnPee++;
		if (TurnPae->GetCard(i).GetKind() == 0) TurnLight++;
	}
	for (i = 0; i < OtherPae->GetNum(); i++) {
		if (OtherPae->GetCard(i).GetKind() >= 3) OtherPee++;
		if (OtherPae->GetCard(i).GetKind() == 0) OtherLight++;
	}

	if (TurnPee >= 10 && OtherPee < 5 && OtherPee != 0) {
		strcat(Mes, "진쪽이 피박입니다. ");
	}
	if (TurnLight >= 3 && OtherLight == 0) {
		strcat(Mes, "진쪽이 광박입니다. ");
	}
	if (OtherPae->GetGo() != 0) {
		strcat(Mes, "진쪽이 독박입니다. ");
	}
	OutPrompt(Mes);
}

void Initialize()
{
	int i;

	for (;;) {
		Deck.Reset();
		South.Reset();
		North.Reset();
		Blanket.Reset();
		Deck.Shuffle();
		for (i = 0; i < 10; i++) {
			South.InsertCard(Deck.Pop());
			North.InsertCard(Deck.Pop());
			if (i < 8) Blanket.InsertCard(Deck.Pop());
		}
		if (South.GetMaxSeries() != 4 && North.GetMaxSeries() != 4 && Blanket.GetMaxSeries() != 4)
			break;
	}
}

void DrawScreen()
{
	clrscr();
	South.Draw(SouthTurn);
	North.Draw(!SouthTurn);
	Blanket.Draw();
	Deck.Draw(false);
	SouthPae.Draw();
	NorthPae.Draw();
}

void OutPrompt(const char* Mes, int Wait/*=0*/)
{
	gotoxy(5, 23);
	for (int i = 5; i < 79; i++) { cout << ' '; }
	gotoxy(5, 23);
	cout << Mes;
	delay(Wait);
}

int InputInt(const char* Mes, int start, int end)
{
	int ch;

	OutPrompt(Mes);
	for (;;) {
		ch = tolower(_getch());
		if (ch == 0xE0 || ch == 0) {
			ch = _getch();
			continue;
		}
		if (!(isdigit(ch) || ch == 'a')) continue;
		if (ch == 'a') ch = 10; else ch = ch - '0';
		if (ch >= start && ch <= end) {
			return ch;
		}
		OutPrompt("무효한 번호입니다. 지정한 범위에 맞게 다시 입력해 주세요.");
	}
}
