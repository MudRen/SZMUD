// Code of ShenZhou
// road: /zhongnan/shenheyuan.c

inherit ROOM;

void create()
{
        set("short","���ԭ");

        set("long",@LONG
�˴�λ�����ɽ�в��Ĵ仪ɽ������������ȥ��ֻ��һƬ̹�������
��ƽԭ������Ⱥɽ֮�䡣��˵�̳�ĩ�꣬�������ʱ��������򳤰�ʱ����
�ݶ�ȱ���ڴ˻�����Ϻ�֮���������������������Ϊ���ԭ�������Ϻ�
���ϸ���һƬ���֡�������һ���ż���
LONG);

        set("exits",([ "southeast" : __DIR__"shulin2",
                        "north" : __DIR__"shulin3",
				"west" : __DIR__"foyezhen",
                      ])
           );
	  set("cost",1);
        set("fjing", 1);
	  set("outdoors", "zhongnan");
        set("objects", ([
				 "/d/village/npc/seller": 1,
				 "/clone/obj/car" : 1,
		  ]));

        setup();

}

