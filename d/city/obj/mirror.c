// Code of ShenZhou
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name(HIY"ͭ��"NOR, ({"tong jing", "mirror", "jing" }) );
        set_weight(2);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
"һ���ͭĥ�ɵľ��ӣ��ճ�������ݣ�\n");
                set("unit", "��");
                set("value", 500);
        }
        init_blade(10);
        setup();
}        
        
void init()
{
	   add_action("do_look","look");
	
}

int do_look(string arg)
{
        object me = this_player();
        object ob = this_object();
	int qper = me->query_per();
	string qname = me->query("name");

	if (!id(arg)) return 0;

	message_vision("$N����һ��ͭ����ϸ������\n\n", me);
	if (this_player()->query("gender") == "Ů��") {
	if (qper<15) 
	{
	write(this_object()->query("long") +"����֮��ò�����Σ����ŵ�һʧ�ְѾ��Ӵ�÷��飡��\n\n");
	destruct(ob);	
	return 1;
}
	if (qper<20)
        {
write(this_object()->query("long") +"�㿴�˿����ӣ����ö���Ҳ����������֮���ˣ���ȻһЦ��ȴҲ��̬��\n\n");
        return 1;
}
 
if (qper<25)
        {
write(this_object()->query("long") +"����֮�����Ǿ��β�ȹ����Ȼ����֮ɫ��Ȼ���֣�ȴ��һ�����ϣ�\n\n");
        return 1;
}          
if (qper<35)
        {
write(this_object()->query("long") +"��������ȥ���˵��Ǳ����߻�֮�ݣ���������֮ɫ��ܽ�����ޣ����Ļش�����\n\n");
        return 1;
}

if (qper>34)        
{
write(this_object()->query("long") +"����֮������֬�ۣ������屾����Ŀ��\n\n");
        return 1;
}

}

        else
{
if (qper<15)
        {
write(this_object()->query("long") +"�����������ɫ��һ�����㼵�ģ����\n\n");
        return 1;
}       
        
if (qper<21)
        {
write(this_object()->query("long") +"�����ͭ�������˰��Σ��Ծ���Ҳ����ٶ�����\n\n");
        return 1;
}        

if (qper<28)
        {
write(this_object()->query("long") +"���й�����������˵����������\n\n");
        return 1;
}
        
if (qper<34)
        {
write(this_object()->query("long") +"��ֻ���Լ���������ǫȻ���Ӷ���\n\n");
        return 1;
}
        
if (qper>33)
        {
write(this_object()->query("long") +"����֮����Ϊ���ᣬ��������һ�㣡\n\n");
        return 1;
}

}

}
