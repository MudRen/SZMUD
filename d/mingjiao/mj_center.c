// Code of ShenZhou
// Room: /d/kunlun/mj_center.c
// Zhangchi 3/00

#include <ansi.h>
inherit ROOM;

int do_check();
int f_set_jingtie(string);
int f_set_didao(string);
string word_string();
string show_data();

void create()
{
	set("short", HIR"����ָ������"NOR);
	set("long", @LONG
����������ָ�����ġ����ܰ����˸��ָ�����������ǽ���滹��
һ��С��(word)������һ��һ����˴�Ĵ���Ļ(screen)����ʾ��һ
Щ���ݡ��
LONG
);
	set("exits", ([
		"out": "/u/zhangchi/workroom",
	]));
	set("valid_startroom", 1);
	set("item_desc", ([
		"word": (: word_string :),
		"screen": (: show_data :),
	]) );
	set("jingtie", 0);
	set("no_clean_up", 1);
	set("didao", ([
		"east":1,
		"west":0,
		"north":0,
		"south":0,
	]));

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
	add_action("f_set_didao","set_didao");
}

int do_check()
{
	write("����"+query("jingtie")+"�龫��\n");
	return 1;
}

int f_set_jingtie(string arg)
{
	int num;

	if (arg)
	{	
		if (sscanf(arg, "%d",num) != 1)
			return notify_fail("ָ���ʽ��set_jingtie <num>\n");
	}
	else
		return notify_fail("ָ���ʽ��set_jingtie <num>\n");
	set("jingtie",num);
	write("OK!\n");
	return 1;
}

int f_set_didao(string arg)
{
	string dir;
	int num;
	
	if (arg)
	{
		if (sscanf(arg, "%s %d", dir, num) != 2)
			return notify_fail("ָ���ʽ��set_didao <dir> <num>\n");
	}
	else
		return notify_fail("ָ���ʽ��set_didao <dir> <num>\n");
	set("didao/"+dir, num);
	write("OK!\n");
	return 1;
}

string word_string()
{
	return HIC
		"�龫��������:		check_jingtie\n"+
		"���þ�������:		set_jingtie <num>\n"+
		"���ú����ص�:		set_didao <dir> <num>\n"
		NOR
		HIR"\n\n���ڽ����С�\n"NOR;
}

string show_data()
{	return HIY
"\n    *-------------------------------------------*"+
	"\n\t����������		"+query("jingtie")+
	"\n\t�����ص���"+
	"\n\t		����	"+query("didao/east")+
	"\n\t		����	"+query("didao/west")+
	"\n\t		����	"+query("didao/north")+
	"\n\t		�ϣ�	"+query("didao/south")+
"\n    *-------------------------------------------*\n\n"+NOR;
}