// Code of ShenZhou
#include "room.h"
inherit ROOM;

void create()
{
  set ("short", "���");
  set ("long", @LONG
�������������߾ͽ���ػ�ʯ���ˣ�����ڻ������񡢲ؾ���
�ƺ��纣����·����һ���޴����ʯ��(shibei)���䱮��ʮ���ߣ�
���߳�һ�硣
LONG);

  set("item_desc", ([ 
  "shibei" : "ʯ�����涼�����֣������ʮ���У�ÿ����ʮ�֡�������ʮ�У�\n"
	     "ÿ����ʮ���֡������籼����������ز���ɷ����ʯī����\n"
	     "�񣬱���Ϊ��ʯ��\n"
]));
  set("outdoors", "/d/qilian");
  set("exits", ([ 
  "eastdown" : __DIR__"mingsha",
  "westup" : __DIR__"shiku",
]));
  replace_program(ROOM);
	set("cost", 2);
  setup();
}

