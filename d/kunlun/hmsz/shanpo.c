// shanpo.c (kunlun)

#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "ɽ����");
                  set("long",@long
�����ɳ���棬����͸�ǣ�ȴҲ��ʵ�Ѱ�,��������ɽ��ת��תȥ��
,���涼�ǻ����ĸ��̲����ʯ��,��Ҳ�Ҳ�����ɽ��;����
long);
                 set("exits",([
"northup" : __DIR__"conglin",
"southdown" : __DIR__"shanao",
  "eastdown" : "/d/kunlun/bayankala",
]));


set("cost", 3);
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
