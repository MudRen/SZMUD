// Code of ShenZhou
// Room: /d/murong/qing9
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
    �鷿����źܶ೤������������������˫ȫ������Щ�²�
͸���﾿����˭��ס����
LONG
	);

	set("cost", 1);
	set("exits", ([ 
        "southeast" : __DIR__"qing6",
                      ]));

	set("no_clean_up", 0);
        
	setup();
	replace_program(ROOM);
}
