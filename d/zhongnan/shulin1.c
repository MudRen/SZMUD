// Code of ShenZhou
// road: /zhongnan/shulin1.c

inherit ROOM;

void create()
{
		  set("short","����");

		  set("long",@LONG
��λ�����ɽ���һ��Ƭ���֣�������Ϊï�ܡ�������䣬ֻ���ý�
��ɳɳ����Ҷ�������ܻ�谵���ģ���ʱ�����չ⴩��Ũ�ܵ�֦ͷ��Ͷ��
���¡�ż��Զ�������޺�����������һ�����ܸС����������ϸ���һ��С
����
LONG);

		  set("exits",([ "southdown" : __DIR__"shanlu4",
								"north" : __DIR__"baozirock",
							 ])
			  );
	  set("cost",2);
	  set("outdoors", "zhongnan");

		  setup();

}

#include "caiyao.h"

