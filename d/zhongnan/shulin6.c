// Code of ShenZhou
// road: /zhongnan/shulin6.c

inherit ROOM;

void create()
{
		  set("short","����");

		  set("long",@LONG
��λ�����ɽ���һ��Ƭ���֣�������Ϊï�ܡ�������䣬ֻ���ý�
��ɳɳ����Ҷ�������ܻ�谵���ģ���ʱ�����չ⴩��Ũ�ܵ�֦ͷ��Ͷ��
���¡�ż��Զ�������޺�����������һ�����ܸС��������ϸ���һ��С����
LONG);

		  set("exits",([ "southup" : __DIR__"shulin5",
							  "northdown" : __DIR__"shanlu15",
						  ])
           );
	  set("cost",2);
	  set("outdoors", "zhongnan");

        setup();

}

#include "caiyao.h"
