// Code of ShenZhou
// cangjingge.c �ؾ���
// by Xiang
// 05/30/96 Marz
// xQin 11/00

inherit ROOM;
#include <ansi.h>

string* books = ({
	"laozi1",
	"daodejing-i",
	"laozi2",
	"daodejing-i",
	"laozi8",
	"daodejing-i",
	"laozi13",
	"laozi1",
	"laozi16",
	"daodejing-i",
	"laozi18"
});

void create()
{
	set("short", "�ؾ���");
	set("long", @LONG
�������˸�¥��̧ͷ������ǰ���������һ��ľ�ң�bian������ǽ��һ
����ܣ������˵��̵ĵ伮��������һ�������εĴ����ӣ�����Ҳ��������
��һ����ͯ�����������鼮��
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"xilang2",
	]));
	
	set("item_desc", ([
		"bian" : YEL"
		��������������������
		��                ��
		��   ��  ��  ��   ��
		��                ��
		��������������������\n\n"NOR,
	]));

	set("objects", ([
		CLASS_D("wudang") + "/daotong" : 1,
		__DIR__"obj/"+books[random(sizeof(books))] : 1,
		__DIR__"obj/"+books[random(sizeof(books))] : 1
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}
