// Code of ShenZhou
// road: /zhongnan/xiaosi.c

inherit ROOM;

void create()
{
        set("short","������");

        set("long",@LONG
����һ��λ�����ɽ��´��С�¡���Ժ�е�һ�ڹž�����Ϊ������
��Ϊÿ���峿������һ�ɾ޴�������Ծ����������𣬲����ο����ˣ�
����Ϊ��һ�۴��澰����������һ����᫵�ɽ����������һ����ɭɭ��
С����
LONG);

        set("exits",([ "north" : __DIR__"haoshanxiaojing6",
                        "southup" : __DIR__"shanlu6",
                      ])
           );
	  set("cost",1);
        set("fjing", 1);

        setup();

        replace_program(ROOM);
}

