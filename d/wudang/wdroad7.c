// Code of ShenZhou
// wdroad7.c ����·
// by Xiang

inherit ROOM;

string* npcs = ({
        "xiao_tufei",
        "xiao_louluo",
});

void create()
{
	set("short", "����·");
	set("long", @LONG
������һ����������Ļ���·�ϣ���������ɭɭ�����֡������Ǻ������磬
��˵���������˳�û�����ɾ������ϱ�һ��С����ͨ���������
LONG
	);
        set("outdoors", "wudang");

//	set("no_sleep_room",1);

	set("exits", ([
		"north" : __DIR__"wdroad6",
		"west" : __DIR__"wdroad8",
		"southup" : __DIR__"tufeiwo0",
	]));

	set("objects", ([
		__DIR__"npc/"+npcs[random(sizeof(npcs))] : 1]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}
