// Code of ShenZhou
// room: didao3.c
//Jay 8/12/96

inherit ROOM;

void create()
{ 
       set("short","�ص�");
       set("long", @LONG
��������һ���ص��С����Ե�ǽ���Ϲ���Щ�͵ƣ��е��Ѿ�Ϩ��
�ˡ����Ϻͽ��µĳ������˺ܲ����������ص���խ�����빭���ǰ��
ǰ��һ�����ţ��������г��������һ�����ס�
LONG
     );
        set("exits", ([
                "southup" : __DIR__"didao2",
		"enter" : __DIR__"dilao1",
        ]));       

        set("no_clean_up", 0);
	set("cost", 1);
        setup();
        replace_program(ROOM);

}

 
