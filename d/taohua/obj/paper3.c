// Code of ShenZhou
// paper.c
inherit ITEM;

void create()
{
        set_name("����", ({"scroll"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"�����ﲻ֪������������֮ʣ����������֮ʣ����������֮ʣ�������Ｘ�Σ�\n");
                set("material", "paper");
        }
}

//����ͬ����ʮϣ������÷����ʮһ֦��������Բ�����£�����������֪��
