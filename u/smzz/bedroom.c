// smzz mk in 2002 5.21 
#include <ansi.h> 
inherit ROOM; 
void create() 
{
set("short",HIC"˯��"NOR);
set("long",
"ɳĮ֮�ӵ�˯��,һ��������ߵ��߾�Ҫ��һ��������\n"
"�Ĵ󷿼�����İ�����ʵ�ܼ�,һ��"MAG"�Չ�ܰ"NOR"��ѹ����\n"
"�ִ�,��һ���Չ�ܰ����վ�ڴ������Ա�һ��С�����������\n"
""HIM"~~~~~~~~~~~~~~~~~~"NOR"\n" 
""HIM"*"HIW"[]"NOR"               "HIM"*\n"NOR 
""HIM"*                 *"NOR"\n" 
""HIM"*"HIW"[]"NOR"               "HIM"*\n"NOR 
""HIM"*                 *"NOR"\n" 
""HIM"~~~~~~~~~~~~~~~~~~"NOR"\n" 
);
set("sleep_room",1);
set("no_fight",1);
set("exits",
([
"down": __DIR__"louti3",
]));
setup();
}
