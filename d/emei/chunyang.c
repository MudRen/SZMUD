// Code of ShenZhou
// chunyang.c ������
// by Shan

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������һǧ���ף������ľ�Դ䣬�ľ����ˡ���ǰ��һʯ��������ʯ��
��˵����������ɽʱ������������Ϣ�����ڴ˿��ݹ۶�����壬�����𶥣���
���ͱڣ�������ߡ�������������ˮ�֣������ǹ��Ƹ�
LONG
        );
        set("exits", ([
		"westup" : __DIR__"shenshui",
                "eastdown" : __DIR__"guiyun",
        ]));

//        set("objects", ([
//		__DIR__"npc/monkey" :3,
//        ]));

	set("outdoors", "emei");

	set("cost", 0);
        setup();
	replace_program(ROOM);
}
