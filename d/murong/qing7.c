// Code of ShenZhou
// Room: /d/murong/qing7
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
    ���Һ����ࡣ������һ��Բ�������İѺ�ľ�������Ŷ�����
���������һ���˾����Ůͯ������ض����㿴��Ŀ������¶
��һ˿ŭ�⡣
LONG
	);
	set("cost", 1);
	set("exits", ([ 
        "west" : __DIR__"qing6",
                      ]));

	set("no_clean_up", 0);
        set("objects", ([
		"/d/murong/npc/buliang" : 1,
		]));

	setup();
	replace_program(ROOM);
}
