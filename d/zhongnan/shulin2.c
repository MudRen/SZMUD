// Code of ShenZhou
// road: /zhongnan/shulin2.c

inherit ROOM;

void create()
{
        set("short","����");

        set("long",@LONG
��λ�����ɽ���һ��Ƭ���֣�������Ϊï�ܡ�������䣬ֻ���ý�
��ɳɳ����Ҷ�������ܻ�谵���ģ���ʱ�����չ⴩��Ũ�ܵ�֦ͷ��Ͷ��
���¡�ż��Զ�������޺�����������һ�����ܸС�����������������һ��
С����
LONG);

        set("exits",([ "northwest" : __DIR__"shenheyuan",
                        "east" : __DIR__"baozirock",
                      ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");

        setup();

}

#include "caiyao.h"

