// Code of ShenZhou
// /d/shenlong/obj/yaofang.c  ҩ��
// by aln  10 / 97

inherit ITEM;

void create()
{
        set_name("ҩ��", ({"yaofang"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "������������д�����֣��г�����ҩ�ݣ����Ʒ����ͷ�����;��\n");
                set("material", "paper");
        }
}
