//����ѵ�߳�   u/spark/trainroom.c
//by spark    5/24/2002

#include <room.h> 
inherit ROOM;

void create()
{
	set("short", "ѵ�߳�"); 
    set("long", @LONG
�����ǰ���ɽׯѵ�����ߵĵط�����ʱ�����������۵İ��յ��ӻ�
�����е�����ָ����Ⱥ�ߵ��ж����������������ȳ�����ʹ������������
Ⱥ��ӿ�����龰��Ȼ���˲���������
LONG
      );
	set("exits", ([
		"northeast" : __DIR__"kongdi2", 
		]));
	set("outdoors","baituo");
	setup();
	set("cost",1);
   	replace_program(ROOM);
}
