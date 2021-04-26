//a command to generate a map for xkx ftb job system
//(admin) (arch)
// by snowyu
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
        object ob;
        string filename="/clone/obj/genmap.c";
        int max_node;

   if( !arg || sscanf(arg, "%d", max_node)!=1 )
                return notify_fail("map �ڵ���\nChu@xkx��˵���ǡ��ڵ����������5������ϵͳ�ܳ��ܶ��٣���֪��:(\n");

        if(max_node>20) 
                return notify_fail("��Ҫ������С��ϵͳ����!\nChu@xkx��˵���������5������ϵͳ�ܳ��ܶ��٣���֪��:(\n");

        if(max_node<=0) 
                return notify_fail("��������");

        if(!find_object(filename))      load_object(filename);
        if(!find_object(filename)) 
                return notify_fail("����ļ���ȫ.\n");
        ob=new(filename);

        ob->start_mapping(max_node);
        return 1;
}
