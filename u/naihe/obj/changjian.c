  // Code of ShenZhou
  // ��ֵǮ�ĳ������������䡣longsword.c ����

#include <ansi.h>
#include <weapon.h>
  inherit SWORD;
  void create()
  {
          set_name("����", ({ "changjian", "jian" }));
          set_weight(5000);
          if (clonep())
                  set_default_object(__FILE__);
          else {
                  set("unit", "��");
                  set("long", "����һ����ͨ�ľ��ֽ���һ��Ľ��Ͷ�����˽���\n");
                  set("value", 0);
                  set("material", "steel");
                  set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                  set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
          }
          init_sword(15);
          setup();
  }
