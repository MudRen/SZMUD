// Code of ShenZhou
// road: /zhongnan/haodian.c

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", HIB"���������"NOR);

        set("long",@LONG
	���������õĸɾ����أ���Ҳ��ʧ��ׯ�����µ����ա�������
������������ȥ��û���ڴ˶�����ֻ�е��һ��С�������Ǩ�ɨ�ء����Ե�
����ϵ���ʮ��֦���򣬲�ʱ����������һ����(zi)���ڵ��۴���������
����������������һ��С�š�
LONG);

		  set("item_desc",(["zi" : "

		�� �� �� ��
		�� ϥ �� ��  ȫ
		�� �� ӿ ��  ��
		�� �� Ȫ ��  ��
		�� �� �� ͨ  ��
		ȵ β �� ��  ��
		�� �� �� ��
		�� �� �� ,
		�� �� ӿ ��
		¥ �� Ȫ ��
		ʮ �� �� ԭ
		�� �� �� ��
		�� �� �� β
		�� �� �� ��
		�� �� ϥ Ѩ
		.  .  .  .

\n",]));

		set("exits",
				([	"southdown" : __DIR__"taijie",
					"north" : __DIR__"yuanneixiaojing7",
				]),
			  );

        set("objects", ([
					 CLASS_D("quanzhen") + "/ma" : 1,
		  ]));




	  set("cost",1);
	  create_door("north", "ľ��", "south", DOOR_CLOSED);

	 setup();

}
