// Code of ShenZhou
// Room: /city/dayuan.c
// YZC 1996/11/13 

inherit ROOM;

void create()
{
	set("short", "��Ժ��");
	set("long", @LONG
������һ�������Χ�ɵĴ�Ժ�ӣ�Ժ�������������ϡϡ����ļ�����������
�����Ų���С���������к�����ӣ����ﰲ���ÿ�����ᵽ���۵�����ζ��Զ��
������������Եø�����࣬�����ݷ����ĳ����γ���һ�������ĶԱȡ�Ժ�����
���������ĵط�����Զ����һƬ���̵���ء�
LONG
	);

	set("exits", ([
                 "yz" : "/shenzhou/d/city/kedian.c",
	]));

	set("objects", ([
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}

