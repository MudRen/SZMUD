// Code of ShenZhou
// Room: /d/murong/huayuan1
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
��Ժ���󣬵����õ���Ϊ���ɡ�����������������裬��Ҷ
��ʱ�ش����ڼ�ɽʯ�ϣ���̬��ǧ��
LONG
	);
	set("cost", 1);
	set("outdoors", "murong");
	set("exits", ([ 
        "south" : __DIR__"qing6",
        "east" : __DIR__"huayuan3",
                      ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
