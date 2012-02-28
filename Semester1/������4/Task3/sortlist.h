#pragma once

struct SList
{
	int value;
	SList *next;
};

int slengh(SList *head);

int sreturnValue(SList *head, int num);

void createEl(SList *tmp, int value);

void sadd(SList *head, int value);

void sdel(SList *head, int num);

void sdelv(SList *head, int value);

void sprintList(SList *head);

void sremoveList(SList *head);