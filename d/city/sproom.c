// Code of ShenZhou
// North teampig room.c 
// Written by Xiang Tu <tu@uwalpha.uwinnipeg.ca>
// Ssy




inherit F_CLEAN_UP;
//inherit ROOM;

#include "teampig.h"

void create()
{
	set("short", "���幰��");
	set("long", @LONG
	����һ��ר��Ϊ���幰�����ƵĹ�������������ƻ�ͨ�����·���
Զ׼����Ϊ������Ƿ����Ƶġ���������ķ���һ���ð���������ľ�����ƵĹ�
����(table)����Χ�����İ��ľ�����Ρ������ϰ���һ���Ƿֲ�(scoreboard)��
���ߵ�ǽ������һ��ֽ(paper)��
        ��ע�⣬���幰���Լҵĳɼ������������ܷ֣������Ϻ���Ҫ��
LONG
	);
	set("pigging", 1);

	set("item_desc", ([
		"table" : (: look_table :),
		"scoreboard" : (: look_scoreboard :),
		"paper" : "����ض� help pig_cmds �� help pig_rules��\n",
	]));

	set("exits", ([
		"north": "/d/city/duchang2",
	]));

	set("no_fight", "1");

	setup();
}

