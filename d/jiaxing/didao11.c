// Code of ShenZhou
// room: mishi.c
//Jay 8/12/96

inherit ROOM;

void create()
{ 
       set("short","�ص�");
       set("long", @LONG
��������һ���ص��С����Ե�ǽ���Ϲ���Щ�͵ƣ��е��Ѿ�Ϩ��
�ˡ����Ϻͽ��µĳ������˺ܲ������
LONG
     );
        set("exits", ([
                "out" : __DIR__"mzqianting1",
		"northdown" : __DIR__"didao12",
        ]));       

        set("no_clean_up", 0);
	set("cost", 1);
        setup();
        replace_program(ROOM);

}

 
