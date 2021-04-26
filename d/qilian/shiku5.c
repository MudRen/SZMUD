// Code of ShenZhou
#include "room.h"
inherit ROOM;

void create ()
{
  set ("short", "ʯ��");
  set ("long", @LONG
��һ�ߵĸ���Ͳ��ܡ��������������������¡ֱͨ���ü��
�۹ġ������ƽ�������������ɮ�£��б�ɴ͸��ĸо����׳�"����
��ˮ"��������̬����������ׯ�ء�ɫ�����졢���κ��ء��ַ����ա�
LONG);

  set("exits", ([ 
  "west" : __DIR__"dtongdao2",
]));
  set("objects", ([
                "/d/emei/obj/yugajing0" : 1,
                "/d/qilian/obj/fojing1" : 1,
                "/d/shaolin/obj/fojing10" : 1,
        ]));

	set("cost", 2);
  setup();
  replace_program(ROOM);
}

