// Code of ShenZhou
#include "room.h"

inherit ROOM;

void create()
{
  set ("short", "���պ�����");
  set ("long", @LONG
��ˮ���Ŵ�Ȫ�ı��ӺӴ��µ����࣬ˮ�ƽ���������ɳɽ����Σ
ɽ���ˢ��һ��ɽ�¶ϲ㡣Ī�߿߾�������������ɳɽ�Ķϲ��ϡ�
LONG);

	set("exits", ([
                "west" : __DIR__"mingsha",

        ]));
	set("outdoors", "/d/qilian");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

