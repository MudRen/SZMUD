// Code of ShenZhou
// Jay 7/11/96

#include <weapon.h>
inherit SWORD;

void create()
{
    set_name("��ü��", ({"emei ci", "ci", "sword"}));
    set_weight(1000); 
    if( clonep() )
      set_default_object(__FILE__);
    else {
      set("long", "����һ�Զ�ü�̣������̽�ʹ�á�\n");
	set("unit","��");
	set("value",400);
	set("material", "iron");
    }
    init_sword(10);

    setup();
}
