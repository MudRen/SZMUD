// Code of ShenZhou
// room: mishi.c
//Jay 8/12/96

inherit ROOM;

void create()
{ 
       set("short","�ص�");
       set("long", @LONG
��������һ���ص��С����Ե�ǽ���Ϲ���Щ�͵ƣ��е��Ѿ�Ϩ��
�ˡ����Ϻͽ��µĳ������˺ܲ�������ص��ϰ�װ��һ�����ţ�һ��
�����������ţ���һ�����ţ���һ�������������š�
LONG
     );
        set("exits", ([
                "southup" : __DIR__"didao1",
		"northdown" : __DIR__"didao3",
        ]));       

        set("no_clean_up", 0);
	set("cost", 1);
        setup();
        replace_program(ROOM);

}

 
