// Code of ShenZhou
#include <ansi.h> 
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(YEL "����Ѽ" NOR, ({"santao ya", "ya"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "�ú�Ѽ��ҰѼ���˸��������䣬�����˲�����ɳ�����Ļ��������\n���ɣ���Ѽ������ҰѼ���֣��˸����ۣ���ζ���أ���ζ���ѣ�����\n�ݸ���Ѽ������������һ�֡�  
\n"  );
                set("unit", "��");
                set("value", 510);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
}
