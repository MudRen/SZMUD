// Code of ShenZhou
// Room: /d/dali/yuxuguan.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�������ʮ����죬���й����Ź��ϡ�������������õȰ��ɵ��������
���ƣ������ϰ���Щ��ҡ����з��˼������š��Ա�һ��С����������Σ�����
��ɢ����Ϣ����ͽ�ĵط���
LONG);
	set("objects", ([
		"/kungfu/class/dali/daobaifeng.c" : 1,
		]));
	set("exits", ([
		"out" : __DIR__"yuxuguan1.c",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
