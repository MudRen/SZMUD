#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;
#include "/clone/unique/special_weapon.h";
void create()
{
     set_name(HIW"ɳĮ������޽�"NOR, ({ "smzz jian", "smzz", "sword" }) );
     set_weight(4000);
     if( clonep() )
          set_default_object(__FILE__);
      else {
           set("unit", "��");
           set("long", 
       CYN"һ���ĳ������ĹŽ�����ϸ���е���������������ý�˿���Ű˸��֣���ɳĮ��嫣��������ޡ���\n"
            NOR);
                 set("value", 10000);
                      set("material", "steel");
                      set("wield_msg",
             CYN"ֻ��ɳĮ֮����ª�׹��һ������ɳĮ��嫣�����������$N�������Ѿ�����һ��$n��ɳĮһ����˭
             ������ !\n"NOR);
                  set("unwield_msg", 
              HIG"$N�����е�$n��һ��ʵ�ʥּ������������������н��ʡ�\n"NOR);
              set("unequip_msg", 
              HIG"$N�����е�$n��һ��ʵ�ʥּ������������������н��ʡ�\n"NOR);
}
     init_sword(19900);
     setup();
     ::create();
}
