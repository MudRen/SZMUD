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

        set("objects", ([
                "/d/wudang/npc/yetu" : 1,
        ]));

        set("exits", ([
                "north" :  __DIR__"forest2",
				"east" : __DIR__"milin19",
        ]));
  
    set("outdoors", "gumu");

	set("cost", 1);
    setup();
	replace_program(ROOM);
}
