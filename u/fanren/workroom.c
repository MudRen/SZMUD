#include <ansi.h>
inherit ROOM;
void create()
{
             set("short", "��֮ª��");
        set("long", @LONG
�����Ƿ���¥�Ĺ�����,����ں�����,ֻ��һյ�谵��С��,���Ϻ�
�����ܲ��ܳ��ܵ���һ�����ѩ,�߽�һ��,ǽ�ϸ������䶼������֩��˿,
Ҳ��֪���������˵�����æʲô������յ�谵�ĵƹ��¾��ڷ���һ̨����
Motorola V70�ֻ���IBM�ʼǱ�����,��Ļ����ʾ��----���ݡ�
LONG);
        set("exits", ([
                  "down" : "/d/city/guangchang",
         "west" : "/d/wizard/wizard_room",

]));
              set("objects",([
           "/u/fanren/npc/muren" : 1,
                 "/u/fanren/npc/singer" : 1,
 ]));
         call_other("/clone/board/fanren_b", "???"); 
                 set("no_sleep", 1);
setup(); 
}
