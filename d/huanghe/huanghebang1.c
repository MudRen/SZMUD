// Code of ShenZhou
// huanghebang1.c �ƺӰ�կ��
// qfy Sept 7, 96

inherit ROOM;

void create()
{
        set("short", "�ƺӰ�կ��");
        set("long", @LONG
����һ������׳�۵�կ�ţ����и߹���һ���ҡ�����д�š��ƺӰ�
���������֡�կ�����ĸ߹ң���ģ��С���ƺӰ��ǻƺ��ذ���һ����
��ᣬƽ�շ�����裬��ѹ���գ������ˡ�����ɳͨ���书��տ��
�����������������̺��������˵ȸ��ֽύ��������ƺƴ󡣾�����
����˹��ᣬ������������
LONG
        );

        set("objects", ([
	    __DIR__"npc/ma-qingxiong" : 1,
	    __DIR__"npc/shen-qinggang" : 1,	
	]));

        set("exits", ([
                "east" : __DIR__"bank1",
		"west" : __DIR__"huanghebang2",
        ]));

	set("outdoors","city");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

