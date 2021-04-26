// Code of ShenZhou
// Ryu, 5/10/97
#include <localtime.h>
#include <ansi.h>;
inherit ROOM;

void create()
{
	mixed *local;
        object *ob;
	local = localtime(time()*60);

	set("short", "��ɽ");
	set("long", @LONG
������𲽣����ϸ߲���������ʱ��ѩ����ɽ��һ��ѩ�߸�����
һ������Ƶ�����ͻȻϮ����ԭ������ʻ�ͦ�����⺮���У�����ѩ
���������˴�ɫ������Ǳ����� "��ɽõ��" ��ѩ����ѩ����������
���������Ϻ�������ƶ�ı�ɽѩ���ϣ�ÿ��ʢ�Ŀ�����һֱ������
���η��ѩ����ʹ��ѩ���׷��У���Ȼ�°��Ű꣬���ͬѩ�����ޣ�
�����뾥ͬ�ݶ����䡣
LONG
	);
	set("exits", ([
                "down" : __DIR__"tianchi",
        ]));
	
        if( local[LT_MON] > 4 && local[LT_MON] < 9 )
	set("objects", ([
		DRUG_D("xuelian") : 1,
	]));

	set("bing_can", 9);
	set("cost", 7);
     set("fjing", 1);
	set("outdoors", "tianshan");

	setup();
}
int valid_leave(object me, string dir)
{
	object *inv;
        int i, flag, j=0;

        inv = all_inventory(me);

	for (i=0; i<sizeof(inv); i++) {
                if ((string)inv[i]->query("id")=="xuelian") j++;
        }

	if( random((int)me->query_skill("dodge")) <= 30
	|| ( j > 0 ) )
        {
                me->receive_damage("qi", 100, "�ӷ嶥��������ˤ����");
                me->receive_wound("qi",  100, "�ӷ嶥��������ˤ����");
                message_vision(HIR"$Nһ��С�Ľ���һ����... ��...��\n"NOR, me);
		me->move(__DIR__"tianchi");
                tell_object(me, HIR"��ӷ嶥���һ�»���������ֻ���û����޴����ۣ������˼����ˡ�\n"NOR);
                message("vision", HIR"ֻ��" + me->query("name") 
		+ "���һ�´ӷ嶥��ֱ������������������ء�\n"NOR, environment(me), me);
	if ( j > 0 )
	for (i=0; i < sizeof(inv); i++) {
                if ( !inv[i]->query("armor_prop/armor") ) {
                        destruct(inv[i]);
			flag += 1;
                }
	   }
	if ( flag ) tell_object(me, "�����ϵĶ�������ͨ��ͨ��������ء�\n");
	}
        return ::valid_leave(me, dir);
}
