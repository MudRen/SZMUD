// Code of ShenZhou
// /d/changbai/xuedi.h

#include <ansi.h>

void init()
{
        object me = this_player();
        int qi = me->query("qi");
        int myforce = (int)me->query_skill("force", 1);

        if( !present("pi qiu", me) && myforce < 100 ) { 
                message_vision(HIR"\nһ�ɴ̹ǵĺ��紵����$Nֻ���û����ѪҺ���챻��ס�ˣ�\n"NOR, me);
//              write("��������һ����ů�����£�һ���ᱻ�����ģ�\n");
                if( (int)me->query("neili") > 3 ) {
                        if( myforce >= 30 )
                                me->improve_skill("force", random(10));
                        me->add("neili", -3);
                } else  me->set("qi", qi*2/3);
        }
}          
