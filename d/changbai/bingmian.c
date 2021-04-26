// Code of ShenZhou
// Room: bingmian.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "����");
	set("long", @LONG
�������ɻ����Ľ��棬���Ѷ����˼��ߺ�ļ�������˻���ƥ��������
�ɺ��⽭�������Σ�ա����������к��Ļ�ѩ������������һƬ��ֻ����
�侭������֮����¶��һ����ɫ�ı�·��
LONG	);
	set("exits", ([ 
              "west" : __DIR__"chuanc",
              "east" : __DIR__"damk",
        ]));
	
        set("outdoors", "changbai");
        set("cost", 6);

	setup();
}

void init()
{
        object me = this_player();
        object weapon, *inv;
        int power;

        power = (int)me->query("dex") * (int)me->query_skill("dodge", 1);
        if( weapon = me->query_temp("weapon") ) power *= 2;

        if( random(power) < 300 ) {
                if( weapon ) {
                        weapon->unequip();
                        weapon->move(environment(me));
                        if( weapon->query("value") < 2000 ) {
                                weapon->set("name", "�ϵ���" + weapon->name());
                                weapon->set("value", 0);
                                weapon->set("weapon_prop", 0);
                        }
                        
                        message_vision(HIR"$N���е�" + weapon->name() + "���ֶ�����\n"NOR, me);
                }
/*
                inv = all_inventory(me);
                for(int i = 0; i < sizeof(inv); i++ )
                        if( !inv[i]->query("armor_prop") )
                                inv[i]->move(this_object());
*/
                message_vision(HIR"\n$Nֻ���ý���һ����ȫ���ڿն��𣬽��ʵʵ��ˤ���˱����ϣ�\n"NOR, me);

                me->receive_damage("qi", 50);
                me->receive_wound("qi", 3 + random(10));
        }
}          
