// Code of ShenZhou
// road: /zhongnan/sunmoonrock.c

inherit ROOM;

void create()
{
        set("short","������");

        set("long",@LONG
һ·������ֻ����ͺͺ��ɽ·���ԣ���ʯ��������Ϊ���ˡ�������ǰ
����Զ���������ʯ����ߵ�һ�����������ұߵ��ǿ���̫�����е�������
����һ������ֻ������һ����Լһ�˶��С��������ͨ���������ºͱ�
���߶���һ�����ѵ�ɽ·��
LONG);

        set("exits",([ "northup" : __DIR__"shanlu4",
                        "eastdown" : __DIR__"shanlu3",
                      ])
           );
	  set("cost",3);
        set("fjing", 1);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}

