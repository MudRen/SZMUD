//  forest1.c
//Jiuer 10-28-2001


inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
Ϫˮ��������һ�����£����������ű�ֱ����׳��ɼ����һ��������
�ش���������ɽ�����¡�����û�������Ļ��֣������ް����ݵ���ȴʢ
���Ÿ�ɫ������ɽ����΢�紵����ɼ�ַ��������֦Х��ɽ���������ҡ
�ڡ����߽����в�������һ������֪�����Ķ��ߡ�
LONG
        );

       // set("objects", ([
         //       "/d/wudang/npc/huoji" : 1,
        //]));

        set("exits", ([
                "east" : __DIR__"milin18",
				"north" : __DIR__"river",
				"south" : __DIR__"forest1",
        ]));
  
    set("outdoors", "gumu");

	set("cost", 1);
    setup();
	replace_program(ROOM);
}
