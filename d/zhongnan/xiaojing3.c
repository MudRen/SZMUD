// Code of ShenZhou
// road: /zhongnan/xiaojing3.c

inherit ROOM;

void create()
{
        set("short", "ɽ��С��");

        set("long",@LONG
����һ��λ�����ɽ�ţ���Ϊ��֪��С�������ܹ�ľ���죬���ֲԴ�
�����ɽ����֦ͷ���񳪺Ͳ��������Ͽɿ���һ��С�ӡ�������ͨ��ɽ��
���
LONG);

        set("exits",([ "south" : __DIR__"river",
                        "east" : __DIR__"xiaojing2",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}
