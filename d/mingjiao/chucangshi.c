// Code of ShenZhou
// Room: /d/mingjiao/chucangshi.c ������
// Zhangchi 3/00

#include <ansi.h>
inherit ROOM;

int do_check();
int f_set_jingtie(int num);
string word_string();

void create()
{
	set("short", "������");
	set("long", @LONG
�����������ؾ����ķ��䡣ǽ������һ��С��(word)��
LONG
	);

	set("item_desc", ([
		"word": (: word_string :),
	]) );
	set("jingtie", 0);
	set("no_clean_up", 0);

	setup();
}

void reset()
{
        ::reset();
        set("no_clean_up", 1);
}

void init()
{
	add_action("do_check","check_jingtie");
	add_action("f_set_jingtie","set_jingtie");
}

int do_check()
{
	write("����"+query("jingtie")+"�龫��\n");
	return 1;
}

int f_set_jingtie(int num)
{
	set("jingtie",num);
	write("OK!\n");
	return 1;
}

string word_string()
{
	return HIC"�龫��������:	check_jingtie\n"+
		"���þ���������	set_jingtie\n"NOR;
}