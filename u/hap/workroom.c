#include <ansi.h>
inherit ROOM;
void create()
{
          set("short", "����С��");
        set("long", @LONG
�����ǿ��Ķ���С���������￴�������ҵģ������������ߵ��Ǹ�λ�ã�
����о��ǳ����ʣ���Ȼ�Ǿ������˾��ĵĲ��á�ǽ�Ϲ��Ÿ�������

            ���費�����п�ͤǰ�������䣻

            ȥ�����⣬���������ƾ����档

LONG);
        set("exits", ([
                  "west" : "/d/city/wumiao",
]));
              set("no_fight", 1); 
              set("valid_startroom",1); 
               call_other("/clone/board/hap_b", "???");  
                 setup(); 
}
