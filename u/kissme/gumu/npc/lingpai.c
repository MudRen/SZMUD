//Code of ShenZhou
//����������
//kissme 2202,2,12

inherit ITEM;

void create()
{
    set_name("�������",({"ling"}));
    set_weight(50);
    if(clonep())
        set_default_object(__FILE__);
    else {
        set("long","������������������ƣ�\n");
        set("unit","��");
        set("value",0);
        }
}


