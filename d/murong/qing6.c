// Code of ShenZhou
// Room: /d/murong/qing6
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
    ��һ�߽����ң����ŵ�һ��֬��ζ�������Ѿ������ھ��ס�ĵط���
��ɫ������͵͵������һ�����ܣ������ط���һ�������£�ɫ������
���š�
LONG
	);
	set("cost", 1);
	set("exits", ([ 
        "south" : __DIR__"qing5",
        "north" : __DIR__"huayuan1",
        "east" : __DIR__"qing7",
        "west" : __DIR__"qing8",
        "northwest" : __DIR__"qing9",
                      ]));

	set("no_clean_up", 0);
        

	setup();
	replace_program(ROOM);
}
