// Code of ShenZhou
// room: didao13.c
//Jay 8/12/96

#include <login.h>

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
                "southup" : __DIR__"didao12",
        ]));       
//        set("valid_startroom",1);

        set("no_clean_up", 0);
	set("cost", 1);
        setup();
        replace_program(ROOM);

}

 
