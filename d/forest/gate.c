// Code of ShenZhou
// gate.c
// Jay 7/12/96

inherit ROOM;

void create()
{
    int i;
        set("short", "��������");
        set("long", @LONG
�����ǽ�����������͵ļ�լ��Ժǽ�����������������(men)���ȡ�
�����ŵ�(deng)��ʣ�ǽ�ڴ�������֮���ò����֡���ʱ�б���������������
�ݸ��ſڵ�Ӷ�ˣ�Ȼ�����¶��롣����һ��С·ͨ��ɽ���¡�
LONG
        );

        set("objects", ([
	    __DIR__"npc/zhangma" : 1,
	]));

        set("exits", ([
                "east" : __DIR__"forest7",
		"west" : __DIR__"foot",
        ]));

	set("item_desc", ([
		"men" : "���Ž��գ�����Ī�롣\n",
		"deng" : "�������߸߹ң��������֡�\n",
	]));
	set("outdoors","city");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

