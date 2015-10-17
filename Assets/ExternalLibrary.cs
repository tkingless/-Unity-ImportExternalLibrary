using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;

public class ExternalLibrary : MonoBehaviour
{
	// On iOS and Xbox 360 plugins are statically linked into
	// the executable, so we have to use __Internal as the
	// library name.
	#if UNITY_IPHONE && !UNITY_EDITOR
	const string dllName = "__Internal";
	#elif UNITY_ANDROID && !UNITY_EDITOR
	const string dllName = "AndroidPlugin";
	#elif UNITY_5_2_1
	const string dllName = "AndroidPlugin";
	#endif

	private static ExternalLibrary singleton_instance = null;

	public static ExternalLibrary instance {
		get {
			if (singleton_instance == null) {
				singleton_instance = FindObjectOfType (typeof(ExternalLibrary)) as ExternalLibrary;
				if (singleton_instance == null) {
					GameObject gob = new GameObject ();
					gob.name = "ExternalPlugin";
					singleton_instance = gob.AddComponent (typeof(ExternalLibrary)) as ExternalLibrary;
				}		
			}
			return singleton_instance;
		}
	}
	
	public float memberVar = 0.0f;
	[DllImport(dllName)] 
	static extern int EXT_LIB_GetNum();

	[DllImport(dllName)]
	static extern void EXT_LIB_PassingVector([In][Out] Vector3[] pnts, [In][Out] float[] floatArray, [In][Out]ref float val);
	public void PassingVector(ref Vector3[] vector3Array, ref float[] floatArray, ref float val)
	{
		int pnum = EXT_LIB_GetNum();
		vector3Array = new Vector3[pnum * 2];
		floatArray = new float[pnum * 2];
		for(int i = 0; i < vector3Array.Length; i++) {
			vector3Array[i].x = (float)i;
			vector3Array[i].y = (float)i;
			vector3Array[i].z = (float)i;
		}
		EXT_LIB_PassingVector(vector3Array, floatArray, ref val);
		memberVar = val;
	}
}
