inherit ITEM;
void create()
{
    set_name("������",({"dali wan","wan"}));
     if(clonep())
    set_default_object(__FILE__);
    else{
    set("unit","��");
    set("value",4000);
      set("long","����һ�Ŵ�����(�������䷲��)��\n");
                set("medicine", 1);
    }
    setup();
}


int cure_ob(object me)
{
      me->set("max_neili",me->query("max_neili")+2);
    me->set("neili",me->query("neili")+200);
    me->set("max_jingli",me->query("max_jingli")+2);
    me->set("jingli",me->query("jingli")+200);
    message_vision("$N����һ�Ŵ����裬��������һ���Ⱥ���\n",me);
    return 1;
}
// ע���������䷲��
