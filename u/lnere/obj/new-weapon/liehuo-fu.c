      // Code of ShenZhou
      //liehuo-fu.c �����һ�
      //Lnere 
       
#include <ansi.h> 
#include <weapon.h> 
      inherit F_UNIQUE; 
      inherit AXE; 
#include "/clone/unique/special_weapon.h" 
       
      void create() 
      { 
              set_name(HIR"�����һ�"NOR, ({ "liehuo fu", "fu", "axe" })); 
              set_weight(50000); 
              if (clonep()) 
                      set_default_object(__FILE__); 
              else { 
                      set("unit", "��"); 
                      set("long",
                      HIW"һ�ѹŴ�����������������У������а���ʹ����ն�����������������������ܡ�������һ���㣬�����ޱȡ�\n"
                      YEL"�����Ͽ���һ��ͼ����ͼ��С�˽������������裬��ͬһ����ƣ�Ʈ��Ʈȥ���仯Ī�⡣\n"NOR);
                      set("value", 50000); 
                      set("material", "steal"); 
                      set("wield_msg", HIR"ͻȻ����й���һ�����ף�$N����˫�۾�����һ��$n��\n"
                      HIR"��״����ĸ�����ҫ��һƬ��⣬��б������ҫ���������ԡ�\n"NOR); 
                        set("unwield_msg", HIW"$n"+HIW+"������£����һ�����õ��ϳ������\n"NOR); 
              } 
              init_axe(140); 
              setup(); 
              ::create(); 
      } 
       
