  // ���ӽ� �� δ����κι���  junzi-jian.c
  // by naihe 2002-06-16

#include <ansi.h>
#include <weapon.h>
  inherit SWORD;

  void create()
  {
          set_name(HIW"���ӽ�"NOR, ({ "junzi jian","sword","jian" }));
          set_weight(1000);
          if (clonep())
                  set_default_object(__FILE__);
          else {
                  set("unit", "��");
                  set("long", "�˽��������ӡ������������ķ�â��Ҳ������Ӱ��������ǣ�����ɱ����\n");
                  set("value", 1);
                  set("material", "steel");
                  set("wield_msg", "$N����س��$n�������С�\n");
                  set("unwield_msg", "$N����ؽ����е�$n��ؽ��ʡ�\n");
          }
          init_sword(100);
          setup();
  }

