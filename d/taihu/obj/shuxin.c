// Code of ShenZhou
// 
inherit ITEM;

void create()
{
        set_name("����", ({"shu xin", "xin"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","���ǹ���ׯ��ׯ��½��Ӣ�������š�\n");
                set("material", "paper");
        }
}

