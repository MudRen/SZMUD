// Code of ShenZhou
// Jay 7/11/96

#include <weapon.h>
inherit CLUB;

void create()
{
    set_name("�йٱ�", ({"panguan bi", "bi"}));
    set_weight(2000); 
    if( clonep() )
      set_default_object(__FILE__);
    else {
      set("long", "����һ֧�����������йٱʣ���һ�����磬"
		"��ͷ����һ��մ��ī����ë��\n");
	set("unit","֧");
	set("value",200);
	set("wield_msg","$N���йٱ�ȡ�����У�˵�����Һ����ѣ�����ͺ���ϾͲ�պī�ˡ�\n");
	set("unwield_msg","$N������������\n");
	set("material", "iron");
    }
    init_club(30);

    setup();
}
